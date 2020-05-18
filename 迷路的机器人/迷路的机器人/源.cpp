class Solution {
public:
	vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> res;

		int row = obstacleGrid.size();
		if (row == 0) return res;
		int col = obstacleGrid[0].size();
		if (col == 0) return res;

		// �����յ����ϰ��������ܵ���
		if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1)
			return res;

		int dp[row + 1][col + 1];
		dp[0][0] = 1;
		// ��ʼ������
		for (int i = 1; i < row; i++) {
			if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
			else dp[i][0] = dp[i - 1][0];
		}
		// ��ʼ������
		for (int i = 1; i < col; i++) {
			if (obstacleGrid[0][i] == 1) dp[0][i] = 0;
			else dp[0][i] = dp[0][i - 1];
		}
		// ��·��
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				}
				else { // ���豣��ͣ��������ļ���
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		// �����յ��·��Ϊ0��ֱ�ӷ���
		if (dp[row - 1][col - 1] == 0) return res;

		// ���յ㷴�ƻ����
		int r = row - 1, c = col - 1;
		while (r != 0 || c != 0) {
			res.push_back({ r, c });

			int up = 0;
			if (r > 0) up = dp[r - 1][c];

			int left = 0;
			if (c > 0) left = dp[r][c - 1];

			if (up >= left) r--;
			else c--;
		}
		res.push_back({ 0, 0 });
		// ע��·����ת
		reverse(res.begin(), res.end());
		return res;
	}
};
