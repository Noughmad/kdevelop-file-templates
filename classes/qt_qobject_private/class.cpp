{% load kdev_filters %}
/*

 {{ license|lines_prepend:" * " }}
 */


#include "{{ output_file_header }}"
#include "{{ output_file_privateheader }}"


{% include "namespace_use_cpp.txt" %}


{{ name }}Private::{{ name }}Private({{ name }}* q) : q_ptr(q)
{

}


{{ name }}Private::~{{ name }}Private()
{

}


{% for method in private_functions %}

{% with method.arguments as arguments %}
{{ method.returnType|default:"void" }} {{ name }}::{{ method.name }}({% include "arguments_types_names.txt" %}){% if method.isConst %} const{% endif %}
{% endwith %}
{


}

{% endfor %}


{% for member in public_members %}

{{ member.type }} {{ name }}::{{ member.name }}() const
{
    Q_D(const {{ name }});
    return d->{{ member.name }};
}

void {{ name }}::set{{ member.name|upper_first }}({{ member.type|arg_type }} {{ member.name }})
{
    Q_D({{ name }});
    if (d->{{ member.name }} != {{ member.name }})
    {
        d->{{ member.name }} = {{ member.name }};
        emit {{ member.name }}Changed(d->{{ member.name }});
    }
}

{% endfor %}


{% for method in public_functions %}

{% include "method_definition_cpp.txt" %}
{% if method.isConstructor %} : d_ptr(new {{ name }}Private(this)){% endif %}
{
    {% if method.isDestructor %}
    delete d_ptr;
    {% endif %}


}

{% endfor %}

{% for method in protected_functions %}

{% include "method_definition_cpp.txt" %}
{% if method.isConstructor %} : d_ptr(new {{ name }}Private(this)){% endif %}
{
    {% if method.isDestructor %}
    delete d_ptr;
    {% endif %}


}

{% endfor %}
