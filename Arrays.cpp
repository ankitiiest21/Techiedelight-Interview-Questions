bool tripletExists(int a[],int n,int sum,int count){
	if(count==3&&sum==0)
		return true;
	if(count==3||sum<0||n==0)
	  return false;
	return (tripletexists(a,n-1,sum-a[n-1],count+1)||tripletexists(a,n-1,sum,count));
}

bool tripletExists(int a[],int n,int sum,int count){
	unordered_map <int,int> mp;
	REP(i,0,n)
	 mp[a[i]]=i;
	REP(i,0,n){
		REP(j,i+1,n){
			int val = sum-(a[i]+a[j]);
			if(mp.find(val)!=mp.end()){
				if(mp[val]!=i&&mp[val]!=j)
				 return true;
			}
		}
	}
	return false;
}


---------------------------------------------------------------------------------------------

bool quadtupleExists(int a[],int n,int sum){
	unordered_map<int,pair<int,int>> mp; //pair is for storing particular indices, summing upto a sum value
	REP(i,0,n-1){
		REP(j,i+1,n){
			int val = sum - (a[i]+a[j]);
			if(mp.find(val)!=mp.end()){
				for(auto pair: mp.find(val)->second){
					int x = pair.first;
					int y = pair.second;
					if(x!=i&&x!=j&&y!=i&&y!=j){
						cout<<"("<<i<<" "<<j<<" "<<x<<" "<<y<<")"<<endl;
						return true;
					}
				}
			}
			mp[a[i]+a[j]].PB({i,j});
		}
	}
	return false;
}

---------------------------------------------------------------------------------------------

bool checkSubarrayWithZeroSum(int a[],int n){
	set<int> s;
	s.insert(0);
	int sum = 0;
	REP(i,0,n){
		sum+=a[i];
		if(s.find(sum)!=s.end())
			return true;
        else
         s.insert(sum);
	}
	return false;
}

void printSubarrayWithZeroSum(int a[],int n){
	unordered_multimap<int,int> mp;
	int sum = 0;
	mp.insert(pair<int,int>(0, -1)); //subarray with 0 sum starts at the index 0
	REP(i,0,n){
     sum+=a[i];
     if(mp.find(sum)!=mp.end()){
     	auto it=mp.find(sum);
     	while(it!=mp.end()&&it->first==sum){
     		cout<<"Subarray: "<<it->second+1<<" ... "<<i<<endl; //follows zero-indexing
     		it++;
     	}
     }
     mp.insert(pair<int,int>(sum,i));
	}
}


-------------------------------------------------------------------------------------------------------------

void maxLengthSubarrayForGivenSum(int a[],int n,int sum){
	unordered_map<int,int> mp;
	int s=0,len=0,end_index=-1;
	mp[0]=-1;
	REP(i,0,n){
     s+=a[i];
     if(mp.find(s)==mp.end())
     	mp[s]=i;
     if(mp.find(s-sum)!=mp.end()&&len<i-mp[s-sum]){
     	len=i-mp[s-sum];
     	end_index=i;
     }
	}
	cout<<end_index-len+1<<" "<<end_index<<endl;
}

// Application-1: Finding maxLengthSubarrayHavingEqualCountOfZerosAndOnes for a binary array is significant 
// to replacing array elements 0 with -1 with sum = 0 for above code

----------------------------------------------------------------------------------------------------------------

//Similar to a fancy Three way partioning for Dutch National Flag Problem.
void sortArrayOfZeroOneTwo(int a[],int n){
	int pivot=1,start=0,mid=0,end=n-1;
	while(mid<=end){
		if(a[mid]<pivot){
			//element is 0
			swap(a[mid],a[start]);
			mid++; start++;
		}
		else if(a[mid]>pivot){
			//element is 2
			swap(a[mid],a[end]);
			mid++; end--;
		}
		else{
			mid++;
		}
	}
}


----------------------------------------------------------------------------------------------------------------------
//O((n+m)log(n+m)) with O(1) extra space


void nextGap(int gap){
	if(gap<=1)
	 return 0;
	return (gap/2)+(gap%2);
}
void mergeTwoSortedArrays(int a[],int b[],int n,int m){
	int gap=n+m,i,j;
	for(gap=nextGap(gap);gap>0;gap=nextGap(gap)){
      for(i=0;i+gap<n;i++){
      	if(a[i]>a[i+gap])
      	 swap(a[i],a[i+gap]);
      }
      for(j=((gap>n)?(gap-n):0);i<n&&j<m;i++,j++){
      	if(a[i]>b[j])
      		swap(a[i],b[j]);
      }
      if(j<m){
      	for(j=0;j+gap<m;j++){
      		if(b[j]>b[j+gap])
      			swap(b[j],b[j+gap]);
      	}
      }
	}
}

------------------------------------------------------------------------------------------------------------------
/*Merge two sorted arrays where first array has exactly same no. of vacant cells as no. of elements in
second array*/
//O(m+n) with O(1) extra space
void merge(int a[],int b[],int m,int n){
	int k=m+n+1; //size of a[]
	while(m>=0&&n>=0){
		if(a[m]>b[n])
		 a[k--]=a[m--];
		else
		 a[k--]=b[n--];
	}
//copying remaining elements of b[](if any)	
	while(n>=0){
		a[k--]=b[n--];
	}

}

void rearrange(int a[],int b[],int m,int n){
	int k=0;
//Stashing all non-zero elements of a to right side	
	REP(i,0,m){
		if(a[i]!=0)
		 a[k++]=a[i];	
	}
//merging a[0...k-1] and b[0...n-1] to a[0...m-1]	
	merge(a,b,k-1,n-1);
}


------------------------------------------------------------------------------------------------------------------

//Finding index of 0 to be replaced to get maximum consecutive ones.

int findIndexToGetMaxLength(int a[],int n){
	int prev=0,curr=0,maxi=INT_MIN;
	REP(i,0,n){
	 if(a[i]==0){
	  curr=i;
	  if(max(maxi,curr-prev)==curr-prev){
	  	maxi=curr-prev;
	  	prev=i;
	  }
	 }
	}
	return prev;
}


-----------------------------------------------------------------------------------------------------------------
//Finding maximum length of subarray containing consecutive elements.

int findMaxLengthSubarrayConsecutiveElements(int a[],int n)
{
 int max_len = 1,mini=INT_MAX,maxi=INT_MIN;
 REP(i,0,n){
 	set<int> s;
 	s.insert(a[i]);
 	REP(j,i+1,n)
 	{
 	 //check for duplicate elements(if any)
 	 if(s.find(a[j])!=s.end())
 	  break;
 	 //push curr element to set and update mini and maxi.
 	 s.insert(a[j]);
 	 mini=min(mini,a[j]);
 	 maxi=max(maxi,a[j]);
 	 if(maxi-mini==j-i){
 	 	max_len=max(max_len,maxi-mini+1);
 	 }	
 	}
 }
 return max_len;
}

-----------------------------------------------------------------------------------------------------------
/*Boyer-Moore Majority vote Algorithm-
Finding majority element(appears more than n/2 times) in O(n) time with O(1) extra space.*/

int majorityElement(int a[],int n){
	int c=0,m;
	REP(i,0,n){
		if(c==0)
		 m=a[i],c=1;
		else{
		 if(c>n/2)
		  return m;
		 ((m==a[i])?c++:c--);
		}
	}
	return -1;
}


--------------------------------------------------------------------------------------------------------------------------------------

//Finding longest bitonic subarray(first increasing then decreasing/always increasing/always decreasing)
//O(n) with O(1) extra space.

int findMaxLengthBitonicSubarray(int a[],int n){
	int len=1,i=0,max_len=INT_MIN,end;
	while(i+1<n){
	 len=1;
     while(i+1<n&&a[i]<a[i+1]){
     	i++;
     	len++;
     }
     while(i+1<n&&a[i]>a[i+1]){
     	i++;
     	len++;
     }
     if(len>max_len){
     	max_len=len;
     	end=i;
     }
	}
    //Bitonic Subarray is from (end-max_len+1 to end)
	return max_len;
}

------------------------------------------------------------------------------------------------------------------------------------------

//Finding longest increasing subsequence of an array..
//O(nlogn) time with O(n) extra space (https://www.youtube.com/watch?v=1RpMc3fv0y4)
//Rule 1: Append if greater
//Rule 2: Replace if smaller

vector<int> findLIS(int a[],int n){
	int parent[n],increasingSubseq[n+1];
	int len=0; //to track the length of LIS
	REP(i,0,n){
     //Binary Search for finding the position 
	 int low=1;
	 int high=len;
     while(low<=high){
     	int mid=(int)ceil((low+high)/2);
     	if(a[increasingSubseq[mid]]<a[i])
     	 low=mid+1;
     	else
     	 high=mid-1;
     }
     int pos=low;
     //updating prev element for LIS
     parent[i]=increasingSubseq[pos-1];
     //Appending or Replacing
     increasingSubseq[pos]=i;
     //updating length of LIS
     if(pos>len)
     	len=pos;
	}
	vector<int> LIS(len,0);
	//Generating LIS by traversing parent array
	int k=increasingSubseq[len];
	REPI(j,0,len){
		LIS[j]=a[k];
		k=parent[k];
	}
	return LIS;
}
