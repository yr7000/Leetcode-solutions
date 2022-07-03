class Solution(object):
    def simplifyPath(self, path):
        stack = []
        cur = ""
        for c in path+"/":
            if(c == "/"):
                if(cur == ".."): 
                    if stack:
                        stack.pop()
                elif (cur != "" and cur != "."): stack.append(cur)
                cur = ""
            else:
                cur += c
        
        return "/" + "/".join(stack)
        