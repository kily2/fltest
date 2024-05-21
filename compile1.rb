

def success(message,error)
  if $?.success?
    puts message
  else
    puts error
    exit 1
  end
end

file_name = "n"
file_name = ARGV[0] if !ARGV.empty?


system("g++ -c #{file_name}.cpp")
success("succeed compile","failed compile")

system("g++ #{file_name}.o -o t -lportaudio -lm -lfltk")
success("succeed linked","failed linked")
