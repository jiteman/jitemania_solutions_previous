#pragma once
// Invoke with a special case for void

#include "catch2/internal/catch_enforce.h"
#include "catch2/internal/catch_interfaces_capture.h"
#include "catch2/internal/catch_interfaces_registry_hub.h"

#include <type_traits>
#include <utility>

namespace Catch {
    namespace Benchmark {
        namespace Detail {
            template <typename T>
            struct CompleteType { using type = T; };
            template <>
            struct CompleteType<void> { struct type {}; };

            template <typename T>
            using CompleteType_t = typename CompleteType<T>::type;

            template <typename Result>
            struct CompleteInvoker {
                template <typename Fun, typename... Args>
                static Result invoke(Fun&& fun, Args&&... args) {
                    return std::forward<Fun>(fun)(std::forward<Args>(args)...);
                }
            };
            template <>
            struct CompleteInvoker<void> {
                template <typename Fun, typename... Args>
                static CompleteType_t<void> invoke(Fun&& fun, Args&&... args) {
                    std::forward<Fun>(fun)(std::forward<Args>(args)...);
                    return {};
                }
            };
            template <typename Sig>
            using ResultOf_t = typename std::result_of<Sig>::type;

            // invoke and not return void :(
            template <typename Fun, typename... Args>
            CompleteType_t<ResultOf_t<Fun(Args...)>> complete_invoke(Fun&& fun, Args&&... args) {
                return CompleteInvoker<ResultOf_t<Fun(Args...)>>::invoke(std::forward<Fun>(fun), std::forward<Args>(args)...);
            }

            const std::string benchmarkErrorMsg = "a benchmark failed to run successfully";
        } // namespace Detail

        template< typename Fun >
        Detail::CompleteType_t< Detail::ResultOf_t< Fun() > > user_code( Fun &&fun ) {
            CATCH_TRY {
                return Detail::complete_invoke( ::std::forward< Fun >( fun ) );
            } CATCH_CATCH_ALL {
                getResultCapture().benchmarkFailed( translateActiveException() );
                CATCH_RUNTIME_ERROR( Detail::benchmarkErrorMsg );
            }
        }
    } // namespace Benchmark
} // namespace Catch
