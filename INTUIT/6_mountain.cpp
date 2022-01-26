// https://docs.google.com/document/d/18oi6OlvcL3wYn20Jb9crW7NO4cGkL6vUfTvplNDGkTw/edit

int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 0, l = mountainArr.length() - 1, mid;
		// Binary Search Peak element
        while(s < l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) s = mid + 1;
            else l = mid;
        }        
        int peak = s;
        
		// Binary Search in First Half
        s = 0; l = peak;
        bool flagL = false, flagR = false;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagL = true;
                break;
            }
            else if(mountainArr.get(mid) < target) s = mid + 1;
            else l = mid - 1;
        }
        if(flagL) return mid;
        
		// Binary Search in second Half
        s = peak + 1; l = mountainArr.length() - 1;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagR = true;
                break;
            }
            else if(mountainArr.get(mid) > target) s = mid + 1;
            else l = mid - 1;
        }
        if(flagR) return mid;
        return -1;
    }