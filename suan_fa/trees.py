def tree(node,branches=[]):
    for branch in branches:
        assert is_tree(branch),"branch must be a tree!"
    return [node]+branches

def node_value(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_leaf(tree):
    if is_tree(tree):
        if len(tree)==1:
            return True
    return False

def is_tree(tree):
    if type(tree)!=list or len(tree)<1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def fib_tree (n):
    if (n<=1):
        return tree(n)
    else:
        return tree(node_value(fib_tree(n-1))+node_value(fib_tree(n-2)),[fib_tree(n-1),fib_tree(n-2)])
    
def leaf_counts(tree): 
    if is_leaf(tree):
        return 1
    else:
        a=[leaf_counts(branch) for branch in branches(tree)]
        return sum(a)
    
def count_paths(t,total):
    if is_leaf(t):
        return node_value(t)==total
    else:
        return (node_value(t)==total) + sum([count_paths(b,total-node_value(t))for b in branches(t)])
    
def sub(t,total):
    if node_value(t)==total:
        found=1
    else:
        found=0
    return found+ sum([sub(b,total-node_value(t))for b in branches(t)])