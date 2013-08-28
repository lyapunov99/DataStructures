#!/usr/bin/ruby

MAX_FLIGHT_NUM = 5000

# Taken from http://www.flashcardmachine.com/jetblue-airport-codes.html
jetblue = ['AUA', 'PHX', 'NAS', 'BDA', 'BGI', 'BUR', 'LAX', 'LGB', 'OAK', 'SMF', 'SAN', 'SFO', 'SJC', 'BOG', 'DEN', 'SJO', 'IAD', 'POP', 'PUJ', 'STI', 'SDQ', 'FLL', 'RSW', 'JAX', 'MCO', 'SRQ', 'TPA', 'PBI', 'ORD', 'KIN', 'MJB', 'MSY', 'PWM', 'BWI', 'ACK', 'HYA', 'MVY', 'PVC', 'CUN', 'SXM', 'LAS', 'EWR', 'BUF', 'SWF', 'JFK', 'LGA', 'ROC', 'SYR', 'HPN', 'CLT', 'RDU', 'PDX', 'PIT', 'BQN', 'PSE', 'SJU', 'UVF', 'AUS', 'HOU', 'SLC', 'BTV', 'RIC', 'SEA']

# Taken from http://www.flashcardmachine.com/swa-airport-codes.html
swa = ['LAX', 'OAK', 'BUR', 'SNA', 'SMF', 'SFO', 'SJC', 'ONT', 'ABQ', 'BOI', 'DEN', 'LAS', 'SAN', 'PHX', 'PDX', 'RNO', 'SLC', 'GEG', 'SEA', 'TUS', 'AMA', 'AUS', 'CRP', 'DAL', 'ELP', 'HRL', 'HOU', 'LBB', 'MAF', 'SAT', 'FLL', 'RSW', 'JAX', 'MCO', 'TPA', 'PBI', 'BHM', 'MDW', 'JAN', 'MCI', 'LIT', 'BNA', 'MSY', 'OKC', 'OMA', 'STL', 'TUL', 'ALB', 'BUF', 'ISP', 'BDL', 'MHT', 'PVD', 'BWI', 'CLE', 'CMH', 'DTW', 'IAD', 'IND', 'SDF', 'ORF', 'PHL', 'PIT', 'RDU', 'MSP']

# Complete list of all airport codes at http://www.kovrik.com/sib/travel/iata-airport-codes.txt
all_airports = jetblue + swa

carriers = ['JETBLUE', 'DELTA', 'DELTA', 'AMERICAN', 'UNITED', 'AIRCANADA', 'SOUTHWEST', 'VIRGIN', 'CATHAY', 'PANAM', 'USAIRWAYS', 'ALASKA','FRONTIER', 'SPIRIT','AIRTRAN']

flightnums = []
flightnumsqueue = []

MAX_FLIGHT_NUM.times do |i|
	flightnums[i] = false
end

activities = ARGV[0].to_i

fh = File.open("activity.log", "w")
activities.times do
	# Legend for operation
	# 1 => Departure
	# 2 => Arrival
	# 3 => Departure Plane Info (!)
	# 4 => Arrival Plane Info (!)
	op = rand(5)
	destination = all_airports[rand(all_airports.length)]
	airline = carriers[rand(carriers.length)]

	case op
		when 1
			fh.write "D\n"
		when 2
			done = false
			flight_num = 0
			while !done do
				flight_num = rand(MAX_FLIGHT_NUM)
				if flightnums[flight_num] == false
					flightnums[flight_num] = true
					done = true
				end
			end
			flightnumsqueue.push(flight_num)
			fh.write("! " + flight_num.to_s + " " + airline + " " + destination + "\n")

		else
			op = rand(3)
			if op == 0
			done = false
			flight_num = 0
				while !done do
					flight_num = rand(MAX_FLIGHT_NUM)
					if flightnums[flight_num] == false
						flightnums[flight_num] = true
						done = true
					end
				end
				flightnumsqueue.push(flight_num)			
				fh.write("$ " + flight_num.to_s + " " + airline + " " + destination + "\n")
			elsif op == 1
				airline = carriers[rand(carriers.length)]
				fh.write("R " + airline + "\n")
			elsif op == 2 and flightnumsqueue.to_a.empty? == false
				flight_num = flightnumsqueue[rand(flightnumsqueue.length)]
				fh.write("R " + flight_num.to_s + "\n")
			end
		end
end
fh.close
