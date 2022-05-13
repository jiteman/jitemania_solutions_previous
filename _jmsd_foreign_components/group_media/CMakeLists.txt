cmake_minimum_required( VERSION 3.7.1 )

project( jmsd_tpc_group_media )


JMSD_SHOW_PROJECT_GROUP_HEADER()

add_subdirectory( jmsd_tpc_glut )

add_subdirectory( jmsd_tpc_zlib )
add_subdirectory( jmsd_tpc_png )
add_subdirectory( jmsd_tpc_freetype )
add_subdirectory( jmsd_tpc_glew )
add_subdirectory( jmsd_tpc_sdl )

###add_subdirectory( jmsd_tpc_openal_soft )
###add_subdirectory( jmsd_tpc_alut )
###add_subdirectory( jmsd_tpc_ogg )
###add_subdirectory( jmsd_tpc_vorbis )
###add_subdirectory( jmsd_tpc_flac )
###add_subdirectory( jmsd_tpc_sfml )


JMSD_SHOW_PROJECT_GROUP_FOOTER()

