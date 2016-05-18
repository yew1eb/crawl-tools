#include<iostream>
#include<vector>
using namespace std;
bool intersect( pair<int,int> a, pair<int,int> b, pair<int,int> &ret ){
  ret.first = max(a.first, b.first);
  ret.second = min(a.second, b.second);
  if( ret.second <= ret.first ) return false;
  else return true;
}
int main(){
  while(true){
    vector< pair<int, int> > xv, yv, zv;
    int n;
    cin >> n;
    if( n == 0 ) break;
    int intersected_x, intersected_y, intersected_z;
    for(int i = 0; i < n; ++i){
      int x, y, z, d;
      cin >> x >> y >> z >> d;
      xv.push_back( make_pair( x, x+d ) );
      yv.push_back( make_pair( y, y+d ) );
      zv.push_back( make_pair( z, z+d ) );
    }
    intersected_x = xv[0].second - xv[0].first;
    intersected_y = yv[0].second - yv[0].first;
    intersected_z = zv[0].second - zv[0].first;

    if( n > 1 ){
      pair<int,int> xintersect, yintersect, zintersect;

      if( !intersect( xv[0], xv[1], xintersect ) )
	intersected_x = 0;
      else
	intersected_x = xintersect.second - xintersect.first;
      for(unsigned int i = 2; i < n; ++i){
	if( !intersect( xintersect, xv[i], xintersect ) ){
	  intersected_x = 0;
	  break;
	}
	intersected_x = xintersect.second - xintersect.first;
      }

      if( !intersect( yv[0], yv[1], yintersect ) )
	intersected_y = 0;
      else
	intersected_y = yintersect.second - yintersect.first;
      for(unsigned int i = 2; i < n; ++i){
	if( !intersect( yintersect, yv[i], yintersect ) ){
	  intersected_y = 0;
	  break;
	}
	intersected_y = yintersect.second - yintersect.first;
      }

      if( !intersect( zv[0], zv[1], zintersect ) )
	intersected_z = 0;
      else
	intersected_z = zintersect.second - zintersect.first;
      for(unsigned int i = 2; i < n; ++i){
	if( !intersect( zintersect, zv[i], zintersect ) ){
	  intersected_z = 0;
	  break;
	}
	intersected_z = zintersect.second - zintersect.first;
      }
    }

    //cout << intersected_x << " " << intersected_y << " " << intersected_z << endl;

    cout << intersected_x * intersected_y * intersected_z << endl;
  }
  return 0;
}