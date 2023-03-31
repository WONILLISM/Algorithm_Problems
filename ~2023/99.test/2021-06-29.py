from typing import List
class Solution:
    def __init__(self):
        self.organization = dict()
        self.senior = str()
        self.junior = str()
        self.answer = 0

    def dfs(self, se, ju, depth):
        print(se)
        if se == ju:
            self.answer = depth
        #if se not in self.organization:
        #    return
        if se in self.organization:
            #i = 0
            for cur in self.organization[se]:
                #print(i)
                #i += 1
                self.dfs(cur, ju, depth + 1)

    def codingteset1(self, hierachy: List[str]) -> int:
        end, start = hierachy[0].split("/")

        for h in hierachy[1:]:
            junior, senior = h.split(("/"))
            if senior not in self.organization:
                self.organization[senior] = []
            self.organization[senior].append(junior)
        #print(self.organization)
        self.dfs(start, end, 0)
        return self.answer



sol = Solution()
# Test1
hierachy = ["Susan/Amy", "Susan/John", "John/Amy"]
print("================")
print("Test1\n")
print(f"Answer : {sol.codingteset1(hierachy)}")
print("================")

sol = Solution()
hierachy = ["Scott/David","Terry/David","Kyle/David", "Ben/Kyle","Scott/Jon","Chris/Scott","Jon/Kenny","Kenny/David","David/Mike"]
print("================")
print("Test2\n")
print(f"Answer : {sol.codingteset1(hierachy)}")
print("================")

sol = Solution()
hierachy = ["Ben/Jon","Terry/David","Kyle/David","Ben/Kyle","Scott/Jon","Chris/Scott","Jon/Kenny","Kenny/David"]
print("================")
print("Test3\n")
print(f"Answer : {sol.codingteset1(hierachy)}")

sol = Solution()
hierachy = ["Christy/Susan","Aimee/Melissa","Melissa/Susan",
"Stacy/Corinne","Gabrielle/Melissa","Corinne/Melissa",
"Christy/Stacy","Pat/Christy"]
print("================")
print("Test4\n")
print(f"Answer : {sol.codingteset1(hierachy)}")
print("================")
