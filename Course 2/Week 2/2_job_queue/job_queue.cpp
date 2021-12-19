#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using std::pair;
using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::greater;
using std::make_pair;


class Worker {
  public:
  int id;
  long long time;

  Worker(int id) {
    this->id = id;
    this->time = 0;
  }
};

struct myComp {
    bool operator()(Worker &a, Worker &b) {
    if (a.time == b.time) return a.id > b.id;
    else return a.time > b.time;
    }
  };

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  
  
  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    priority_queue<Worker, vector<Worker>, myComp> pq;

    for (int i = 0; i < num_workers_; i++) {
      pq.push(Worker(i));
    }

    for (int i = 0; i < jobs_.size(); i++) {
      Worker th = pq.top();
      pq.pop();
      assigned_workers_[i] = th.id;
      start_times_[i] = th.time;
      th.time += jobs_[i];
      pq.push(th);
    }

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
