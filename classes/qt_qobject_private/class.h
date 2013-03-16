{% extends "cpp_header_onlyfunctions.h" %}
{% load kdev_filters %}

{% block forward_declarations %}
class {{ name }}Private;
{% endblock forward_declarations %}



{% block class_declaration_open %}
{{ block.super }}
    Q_OBJECT
    {% for member in public_members %}
    Q_PROPERTY({{ member.type }} {{ member.name }} READ {{ member.name }} WRITE set{{ member.name|capfirst }} NOTIFY {{ member.name }}Changed)
    {% endfor %}
{% endblock class_declaration_open %}

{% block class_body %}
{% if public_functions %}
public:
{% endif %}
{% for method in public_functions %}
{% include "method_declaration_cpp.txt" %}
{% endfor %}


{% if public_members %}
public:
{% for member in public_members %}
    {{ member.type }} {{ member.name }}() const;
{% endfor %}


public Q_SLOTS:
{% for member in public_members %}
    void set{{ member.name|upper_first }}({{ member.type|arg_type }} {{ member.name }});
{% endfor %}


Q_SIGNALS:
{% for member in public_members %}
    void {{ member.name }}Changed({{ member.type|arg_type }} {{ member.name }});
{% endfor %}
{% endif %}

{% if protected_functions %}
protected:
{% endif %}
{% for method in protected_functions %}
{% include "method_declaration_cpp.txt" %}
{% endfor %}

{% endblock class_body %}


{% block class_bottom %}
private:
    class {{ name }}Private* const d_ptr;
    Q_DECLARE_PRIVATE({{ name }})
{% endblock class_bottom %}
