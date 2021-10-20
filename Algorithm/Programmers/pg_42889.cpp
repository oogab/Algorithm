//#include <string>
//#include <vector>
//#include <cstdio>
//#include <algorithm>
//#include <functional>
//
//using namespace std;
//
//vector<int> solution(int N, vector<int> stages) {
//    vector<int> answer(N);
//    int user_num = stages.size();
//    vector<int> fail_stage_challenger(N);
//    vector<int> total_stage_challenger(N);
//    vector<double> stage_fail_rate(N);
//
//    for (int i = 0; i < user_num; i++) {
//        int cnt = stages[i];
//        if (cnt != N + 1) {
//            fail_stage_challenger[cnt - 1] += 1;
//            for (int j = 1; j <= cnt; j++) {
//                total_stage_challenger[j - 1] += 1;
//            }
//        }
//        else {
//            for (int j = 1; j < cnt; j++) {
//                total_stage_challenger[j - 1] += 1;
//            }
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//        if (total_stage_challenger[i] == 0) {
//            stage_fail_rate[i] = 0.0;
//            continue;
//        }
//        stage_fail_rate[i] = (double)fail_stage_challenger[i] / (double)total_stage_challenger[i];
//    }
//
//    vector<double> tmp_rate = stage_fail_rate;
//    sort(tmp_rate.begin(), tmp_rate.end(), greater<double>());
//
//    for (int i = 0; i < N; i++) {
//        double rate = tmp_rate[i];
//        for (int j = 0; j < N; j++) {
//            if (rate == stage_fail_rate[j]) {
//                answer[i] = j + 1;
//                stage_fail_rate[j] = -1.0;
//                break;
//            }
//        }
//    }
//
//    return answer;
//}