{% load kdev_filters %}
/*

{{ license|lines_prepend:" * " }}
 */


import QtQuick 1.1


Item {
    {% for member in members %}
    property {{ member.type }} {{ member.name }}{% if member.value %}: {{ member.value }}{% endif %}
    {% endfor %}
    
    
    {% for function in functions %}
    
    {% with function.arguments as arguments %}
    function {{ function.name }}({% include "arguments_names.txt" %}) {
        
    }
    
    {% endwith %}
    {% endfor %}
}