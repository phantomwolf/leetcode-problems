record CheckInInfo(String station, int t) {} 

public class UndergroundSystem {
    // id => (stationName, t)
    Map<Integer, CheckInInfo> checkInTimes = new HashMap<>();
    // startStation => {endStation => [totalTravels, timeSum]}
    Map<String, Map<String, int[]>> travelTimes = new HashMap<>();

    public UndergroundSystem() {
        
    }

    public void checkIn(int id, String stationName, int t) {
        checkInTimes.put(id, new CheckInInfo(stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        CheckInInfo checkIn = checkInTimes.remove(id);

        int[] pair = travelTimes
            .computeIfAbsent(checkIn.station(), k -> new HashMap<>())
            .computeIfAbsent(stationName, k -> new int[2]);
        pair[0]++;
        pair[1] += t - checkIn.t();
    }
    
    public double getAverageTime(String startStation, String endStation) {
        int[] pair = travelTimes.get(startStation).get(endStation);
        return pair[1] / (double)pair[0];
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */