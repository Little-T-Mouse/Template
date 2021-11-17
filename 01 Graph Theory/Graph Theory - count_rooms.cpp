void count_rooms(int r, int c) {
    grid[r][c] = 'X'; // change 'X' to the wall in the specific question
    // go up
    if(r > 0 && grid[r-1][c] == '.') count_rooms(r-1, c);
    // go down
    if(r < R-1 && grid[r+1][c] == '.') count_rooms(r+1, c);
    // go left
    if(c > 0 && grid[r][c-1] == '.') count_roomsd(r, c-1);
    // go right
    if(c < C-1 && grid[r][c+1] == '.') count_rooms(r, c+1);
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '.') {
                count_rooms(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
