#include <algorithm>
#include <cstddef>
#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum Action {
  ACT_DOWN_LEFT = 1,
  ACT_DOWN,
  ACT_DOWN_RIGHT,
  ACT_LEFT,
  ACT_STAY,
  ACT_RIGHT,
  ACT_UP_LEFT,
  ACT_UP,
  ACT_UP_RIGHT
};

const pair<int, int> DELTA[] = {{1, -1}, {1, 0},   {1, 1},  {0, -1}, {0, 0},
                                {0, 1},  {-1, -1}, {-1, 0}, {-1, 1}};

class Board {
private:
  const size_t _row, _col;
  optional<pair<int, int>> _iPosition;
  vector<pair<int, int>> _rPositions;

  Board(size_t row, size_t col) : _row{row}, _col{col} {}

  bool _isValidPosition(pair<int, int> pos) const {
    auto [x, y] = pos;
    return (x >= 0 && x < _row && y >= 0 && y < _col);
  }

public:
  Board(Board &&) = default;

  pair<int, int> getIPosition() const { return _iPosition.value(); }

  const vector<pair<int, int>> &getRPositions() const { return _rPositions; }

  void moveI(Action act) {
    auto [x, y] = _iPosition.value();
    auto [dx, dy] = DELTA[act - 1];
    pair<int, int> newIPos = {x + dx, y + dy};
    if (!_isValidPosition(newIPos)) {
      throw runtime_error("moveI: invalid move action");
    }
    _iPosition = newIPos;

    auto it = std::find(_rPositions.begin(), _rPositions.end(), newIPos);
    if (it != _rPositions.end()) {
      _rPositions.erase(it);
      _iPosition.reset();
    }
  }

  void moveR(const vector<Action> &actions) {
    if (actions.size() != _rPositions.size()) {
      throw runtime_error("moveR: count of provided actions doesn't match");
    }

    size_t n = 0;
    vector<int> dup_cnt(_row * _col, 0);
    for (auto [x, y] : _rPositions) {
      auto [dx, dy] = DELTA[actions[n++] - 1];
      auto [nx, ny] = pair{x + dx, y + dy};
      dup_cnt[nx * _col + ny]++;
    }

    auto [ix, iy] = _iPosition.value();
    if (dup_cnt[ix * _col + iy] > 0) {
      dup_cnt[ix * _col + iy] = 0;
      _iPosition.reset();
    }

    _rPositions.clear();
    int idx = 0;
    for (auto v : dup_cnt) {
      if (v == 1) {
        _rPositions.push_back({idx / _col, idx % _col});
      }
      idx++;
    }
  }

  static Board deserialize(const string &data) {
    stringstream ss{data};

    size_t row, col;
    if (!(ss >> row >> col)) {
      throw runtime_error("deserialize: invalid board data");
    }

    Board board{row, col};
    char cellType;
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < col; j++) {
        if (ss >> cellType) {
          switch (cellType) {
          case 'I':
            if (board._iPosition.has_value()) {
              throw runtime_error(
                  "deserialize: cell type of 'I' must be uniquely exist");
            }
            board._iPosition = {i, j};
            break;
          case 'R':
            board._rPositions.push_back({i, j});
            break;
          case '.': // fall through
          default:
            break;
          }
        }
      }
    }

    return board;
  }

  bool isLost() const { return !_iPosition.has_value(); }

  string to_string() const {
    string str(_row * (_col + 1), '.');
    for (size_t i = 0; i < _row; i++) {
      str[i * (_col + 1) + _col] = '\n';
    }
    str.pop_back();

    if (_iPosition.has_value()) {
      auto [x, y] = _iPosition.value();
      str[x * (_col + 1) + y] = 'I';
    }
    for (auto [x, y] : _rPositions) {
      str[x * (_col + 1) + y] = 'R';
    }
    return str;
  }

  string serialize() const {
    stringstream ss;
    ss << _row << " " << _col << "\n";
    ss << this->to_string();
    return ss.str();
  }
};

class RobotsGame {
private:
  Board _board;

public:
  RobotsGame(Board &&board) : _board(std::move(board)) {}

  bool step(Action action) {
    _board.moveI(action);
    if (_board.isLost()) {
      return false;
    }

    auto [ix, iy] = _board.getIPosition();
    vector<Action> rActions;
    for (auto [rx, ry] : _board.getRPositions()) {
      int a = 1;
      if (rx == ix) {
        a += 3;
      } else if (rx > ix) {
        a += 6;
      }
      if (ry == iy) {
        a += 1;
      } else if (ry < iy) {
        a += 2;
      }
      rActions.push_back(static_cast<Action>(a));
    }
    _board.moveR(rActions);

    return !_board.isLost();
  }

  string printBoard() const { return _board.to_string(); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int R, C;

  cin >> R >> C;

  stringstream ss;
  ss << R << " " << C << "\n";
  cin.ignore();
  for (size_t i = 0; i < R; i++) {
    string s;
    getline(cin, s);
    ss << s << "\n";
  }

  RobotsGame game{Board::deserialize(ss.str())};

  string actions;
  getline(cin, actions);
  int steps_cnt{0};
  bool is_lost = false;
  for (char act : actions) {
    steps_cnt++;
    if (!game.step(static_cast<Action>(act - '0'))) {
      is_lost = true;
      break;
    }
  }
  if (is_lost) {
    cout << "kraj " << steps_cnt << endl;
  } else {
    cout << game.printBoard() << endl;
  }

  return 0;
}
