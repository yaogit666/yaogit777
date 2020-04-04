class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image[sr][sc] == newColor)
			return image;
		int oldColor = image[sr][sc];
		image[sr][sc] = newColor;
		Find(image, sr - 1, sc, newColor, oldColor);
		Find(image, sr, sc - 1, newColor, oldColor);
		Find(image, sr, sc + 1, newColor, oldColor);
		Find(image, sr + 1, sc, newColor, oldColor);
		return image;
	}

	void Find(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
	{
		if (sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size() && image[sr][sc] == oldColor)
		{
			image[sr][sc] = newColor;
			Find(image, sr - 1, sc, newColor, oldColor);
			Find(image, sr, sc - 1, newColor, oldColor);
			Find(image, sr, sc + 1, newColor, oldColor);
			Find(image, sr + 1, sc, newColor, oldColor);
		}
	}
};