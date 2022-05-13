cmake_minimum_required( VERSION 3.7.1 )

project( jms_framework_old )


JMSD_SHOW_PROJECT_GROUP_HEADER()


set( JMSD_COMPONENT_CMAKE_SETTINGS_PATH ${PROJECT_SOURCE_DIR}/_cmake_settings )


# libraries
add_subdirectory( encodebuba )
add_subdirectory( al_std )
add_subdirectory( al_qt )
##add_subdirectory( jmsf_basing )
##add_subdirectory( jmsf_basing_researching )
##add_subdirectory( jmsf_basing_experimenting )
add_subdirectory( jmsf )
add_subdirectory( jmsf_researching )
##add_subdirectory( jmsf_experimenting )
add_subdirectory( tdd_learning )

if ( WIN32 )
	add_subdirectory( ms_windows )
endif()
#~libraries

# testing and mocking framework
add_subdirectory( cule )
#add_subdirectory( fakeit )
#~testing and mocking framework

# tests
add_subdirectory( jmsf_tests_ )
#add_subdirectory( fakeit_tests_ )
#~tests


JMSD_SHOW_PROJECT_GROUP_FOOTER()
