project(kdevelop-file-templates)

find_package(KDE4 REQUIRED)
find_package(KDevPlatform 1.5.0 REQUIRED)

include(KDE4Macros)

set(filetemplate_DIRS
    classes/qml_item
    classes/qt_qobject_private
    other/gsl_ode_solver
)

kdevplatform_add_file_templates(${filetemplate_DIRS})
