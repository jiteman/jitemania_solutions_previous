cmake_minimum_required( VERSION 3.7.1 )

project( _jmsd_migration_components )


JMSD_SHOW_PROJECT_GROUP_HEADER()


#add_subdirectory( cmof_original )
add_subdirectory( cmof_jmsd )
#add_subdirectory( catch2_original )
add_subdirectory( catch2_jmsd )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
