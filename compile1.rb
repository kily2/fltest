

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



list = [
	"n",
	"src/UI/UserInterface",
	"src/Audio/AudioFileHandler",
	"src/Audio/AudioEngine",
]



def extract_name(path)
	file_name = path.match(/[^\/]+$/)[0]
end



def compile(list)
	list.each do |file|
		file_name = extract_name(file)
		system("g++ -c #{file}.cpp -o objects/#{file_name}.o")
		success("succeed #{file} compile","failed #{file} compile")
	end	
	puts "All compiled successfuly."
end



def link(list)
	flat_list = list.map { |file| "objects/"+extract_name(file)+".o" }.join(" ")
	system("g++ #{flat_list} -o t -lportaudio -lm -lfltk -lsndfile")
	success("succeed linked","failed linked")
end



compile(list)
link(list)



#### compile1.rb

