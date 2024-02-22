//link -https://www.codingninjas.com/studio/problems/count-of-greater-elements-to-the-right_8365436
vector<int> countGreater(vector<int>&arr, vector<int>&query) {


    //Logic 
    for(int itr1=0;itr1<query.size();itr1++)
    {
        for(int itr2=query[itr1]+1;itr2<arr.size();itr2++)
        {    
            if(arr[query[itr1]]<arr[itr2])
            {
                count++;
            }
        }        
        query[itr1]=count;
        count=0;
    }
    return query;
}
