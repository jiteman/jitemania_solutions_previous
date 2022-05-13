cmake_minimum_required( VERSION 3.7.1 )

project( _jmsd_tpa_components )


JMSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( jmsd_tpa_cppunit )
add_subdirectory( jmsd_tpa_gtm )

# tests
#add_subdirectory( jmsd_tpa_poco )
#~tests


JMSD_SHOW_PROJECT_GROUP_FOOTER()
