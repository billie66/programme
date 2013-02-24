#!/usr/bin/env ruby

def camel_case(str)
  return self if self !~ /_/ && self =~ /[A-Z]+.*/
    str.split('_').map{|e| e.capitalize}.join
end

def camel_case_lower
  self.split('_').inject([]){ |buffer,e| buffer.push(buffer.empty? ? e : e.capitalize) }.join
end

puts camel_case("foo_bar")      
puts "foo_bar".camel_case_lower
