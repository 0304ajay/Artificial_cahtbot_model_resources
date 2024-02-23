//link -https://www.codingninjas.com/studio/problems/asteroid-collision_977232?leftPanelTabValue=PROBLEM
vector<int> collidingAsteroids(vector<int>& asteroids)
{
    //declaration
    stack<int> stk;
    int sz = asteroids.size();
    bool same = false;
    vector<int> result;
    //logic
    stk.push(asteroids[0]);

    for (int idx = 1; idx < sz; idx++)
    {
        if (asteroids[idx] == 0)
        {
            continue;
        }
        if (!stk.empty() and asteroids[idx]<0 and stk.top()>abs(asteroids[idx]))
        {

        }
        else if (!stk.empty() and stk.top() > 0 and stk.top() <= abs(asteroids[idx]) and asteroids[idx] < 0)
        {
            //=
            while (!stk.empty() and stk.top() <= abs(asteroids[idx])and stk.top()>0)
            {
                if (stk.top() == abs(asteroids[idx]))
                {
                    same = true;
                    stk.pop();
                    break;
                }
                else {
                    stk.pop();
                }
            }
            if (!stk.empty() and stk.top() > abs(asteroids[idx]))
            {

            }
            else if (same == false)
            {
                stk.push(asteroids[idx]);
            }
            same = false;
        }
        else {
            stk.push(asteroids[idx]);
        }
    }
    while (stk.top() == 0)
    {
        stk.pop();
    }
    sz = stk.size();
    for (int idx = 0; idx < sz; idx++)
    {
        result.push_back(stk.top());
        stk.pop();
    }
    reverse(result.begin(), result.end());
    return result;

}
