#!/usr/bin/env ruby

file = File.open("a.rb") if File.file?("a.rb")

file1 = File.open("b.rb", "a+") 

while line = file.gets
  file1.puts line
end 

puts File.read("a.rb"), "c.rb"

file.close
file1.close
    

