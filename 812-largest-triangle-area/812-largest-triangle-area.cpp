class Solution {
public:
    double area(vector<int>a ,vector<int>b ,vector<int>c)
	{
		return abs((a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1])));
	}
    double largestTriangleArea(vector<vector<int>>&pt) {
        double ans=0;
		for(int i=0;i<pt.size()-2;i++)
		{
			for(int j=i+1;j<pt.size()-1;j++)
			{
				for(int k=j+1;k<pt.size();k++)
					ans=max(ans,area(pt[i],pt[j],pt[k]));
			}
		}
		return ans/2;
    }
};
