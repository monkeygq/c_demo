output = File.new("#{ARGV.first}.available", "w")
File.open(ARGV.first, "r") do |file|
	while line = file.gets
		sample_period = line.split("=").last.strip
		line = file.gets
		line = file.gets
		sample_count = line.split("(").last.split.first
		output.puts "#{sample_period} #{sample_count}"
	end
end
output.close
