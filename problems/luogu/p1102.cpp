    #include <iostream>
    #include <map>

    using namespace std;

    long long n, k, x;
    map<long long, long long> data1;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> x;
            data1[x]++;
        }
        auto li=data1.begin(),ri=data1.begin();
        long long total=0;
        if(k==0){
            while(ri!=data1.end()){
                total+=((*ri).second-1)*(*ri).second/2;
                ri++;
            }
            cout << total;
            return 0;
        }
        while(ri!=data1.end()&&li!=data1.end()){
            if(((*ri).first-(*li).first)==k){
                total+=(*ri).second*(*li).second;
                li++;ri++;
            }else if(((*ri).first-(*li).first)>k){
                li++;
            }else if(((*ri).first-(*li).first)<k){
                ri++;
            }
        }
        cout << total;
        return 0;
    }