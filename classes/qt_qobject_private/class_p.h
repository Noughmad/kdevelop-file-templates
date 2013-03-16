{% load kdev_filters %}
/*

 {{ license|lines_prepend:" * " }}
 */


#ifndef {{ name|upper}}_PRIVATE_H
#define {{ name|upper}}_PRIVATE_H


#include <QtCore/qglobal.h>


{% include "namespace_open_cpp.txt" %}

class {{ name }};
class {{ name }}Private
{
public:
    {{ name }}Private({{ name }}* q);
    virtual ~{{ name }}Private();


    {% for method in private_methods %}
        {% include "declaration.txt" %}
    {% endfor %}


    {% for member in members %}
    {{ member.type }} {{ member.name }};
    {% endfor %}


private:
    {{ name }}* const q_ptr;
    Q_DECLARE_PUBLIC({{ name }})
};


{% include "namespace_close_cpp.txt" %}


#endif // {{ name|upper}}_PRIVATE_H
