
return if ARGV.size < 3

file_name = ARGV[0]

file_contents = File.read(file_name)

modified_contents = file_contents.gsub(ARGV[1], ARGV[2])

File.write(file_name, modified_contents)

puts "done."





###

