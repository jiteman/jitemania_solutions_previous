cmake_minimum_required( VERSION 3.7.1 )

project( jmsd_tpc_group_autotesting )


JMSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( jmsd_tpc_googletest )
add_subdirectory( jmsd_tpc_cppunit )


JMSD_SHOW_PROJECT_GROUP_FOOTER()
