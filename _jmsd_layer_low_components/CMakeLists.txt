cmake_minimum_required( VERSION 3.7.1 )

project( _jmsd_layer_low_components )


JMSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( jmsd_component ) # template
add_subdirectory( jmsd_component_with_tests ) # template
add_subdirectory( jmsd_nutfield ) # native unit-testing framework


JMSD_SHOW_PROJECT_GROUP_FOOTER()
