class UndergroundSystem {
public:
//     creating a hash table to store the id, and corresponding station and its checkin time
    unordered_map<int,pair<string,double> > check;
//     creating another hash table to store travel detail as a string and its corresponding travel time and frequency
    unordered_map<string,pair<double,double> > time;
    
    UndergroundSystem() {
        
    }
    
//     updating all the checkins 
    void checkIn(int id, string stationName, int t) {
        check[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
//     creating a string to store travel detail, start to end station
        string travel=check[id].first+"->"+stationName;
//         updating the travel time and its frequency for a given travel detail
        time[travel]={(t-check[id].second)+time[travel].first,time[travel].second+1};
//         free up memory for completed id
        check.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string checkTravel=startStation+"->"+endStation;
//         finding the avg travel time for given travel detail using travel time and its frequency
        double ans=time[checkTravel].first/time[checkTravel].second;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */