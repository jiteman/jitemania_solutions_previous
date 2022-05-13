cmake_minimum_required( VERSION 3.7.1 )

project( library_subproject_template )


JMSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( base_library_template )
add_subdirectory( derived_library_template )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
