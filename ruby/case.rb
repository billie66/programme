#!/usr/bin/env ruby

page = 2 
pages = 3 

case page
  when 0
    puts '0' 
  when 1..pages 
    puts '1' 
  when 5...7 
    puts '3' 
  else puts '4' 
end

