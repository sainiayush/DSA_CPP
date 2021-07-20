bool isv4(string IP){
        IP+='.';
        
        vector<string>ip;
        
        for(int i=0;i<IP.length();++i){
            string t="";
            
            while(IP[i]!='.'){
                if(IP[i]>='0' && IP[i]<='9')
                    t+=IP[i++];
                
                else
                    return 0;
            }
                
                if(t.compare("")==0)
                    return 0;
                
                if(t.length()!=1 && t[0]=='0')
                    return 0;
                
                if(t.length()>3)
                    return false;
                ip.push_back(t);
            
            
        }
        
         if(ip.size()!=4)
                return false;
            
            for(int j=0;j<ip.size();++j)
            {
                if(stoi(ip[j])>255)
                    return 0;
            }
        return true;
    }
    bool isv6(string IP){
        IP+=':';
        
        vector<string>ip;
        for(int i=0;i<IP.length();++i){
            string t="";
            
            while(IP[i]!=':'){
            if((IP[i]>='0' && IP[i]<='9') || (IP[i]>='a' && IP[i]<='f') || (IP[i]>='A' && IP[i]<='F'))
                t+=IP[i++];
                else return 0;
            }
            
            if(t.compare("")==0)
                return 0;
            if(t.length()>4)
                return 0;
            ip.push_back(t);
        }
        
        if(ip.size()!=8)
            return 0;
        
        
        return 1;
        
    }
    string validIPAddress(string IP) {
        
        for(int i=0;i<IP.length();++i){
            if(IP[i]=='.'){
                if (isv4(IP))
                    return "IPv4";
                return "Neither";
            } 
            if(IP[i]==':'){
                if(isv6(IP))
                    return "IPv6";
                return "Neither";
            }
        }
        return "Neither";
    }
