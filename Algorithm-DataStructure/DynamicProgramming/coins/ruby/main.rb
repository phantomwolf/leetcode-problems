#!/usr/bin/env ruby


COINS = [1, 3, 5]

def coins(target)
    d = [0]
    choice = [0]
    for i in 1..target
        tmp = []
        for j in 0..2
            if COINS[j] > i
                tmp[j] = 9999999
            else
                tmp[j] = d[i - COINS[j]] + 1
            end
        end

        min_index = tmp.index(tmp.min)
        d[i] = tmp[min_index]
        choice[i] = COINS[min_index]
    end
    puts "$#{target} need coins: #{d[target]}"

    puts "choices: #{choice}"
    # print choices of target
    print "choices: "
    while target != 0
        print "#{choice[target]}, "
        target -= choice[target]
    end
    puts ""
end

coins(11)
