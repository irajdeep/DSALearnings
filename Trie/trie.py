class TrieNode:
    def __init__(self):
        self.isLeaf = False
        self.children = [None] * 26


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        nav = self.root
        lens = len(word)

        for pos, ch in enumerate(word):
            index = ord(ch) - ord('a')
            if nav.children[index] is None:
                nav.children[index] = TrieNode()
            nav = nav.children[index]
            if pos == lens - 1:
                nav.isLeaf = True

        return False

    def search(self, word: str) -> bool:
        nav = self.root
        lens = len(word)

        for pos, ch in enumerate(word):
            index = ord(ch) - ord('a')
            if nav.children[index] is None:
                return False
            nav = nav.children[index]
            if pos == lens - 1:
                if nav.isLeaf == True:
                    return True
        return False

    def startsWith(self, prefix: str) -> bool:
        nav = self.root

        for ch in prefix:
            index = ord(ch) - ord('a')
            if nav.children[index] is None:
                return False
            nav = nav.children[index]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
