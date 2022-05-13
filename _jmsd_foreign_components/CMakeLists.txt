cmake_minimum_required( VERSION 3.7.1 )

project( _jmsd_foreign_components )


JMSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( jmsd_tpc_component )
add_subdirectory( group_autotesting )
add_subdirectory( group_foundation )
add_subdirectory( group_media )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
