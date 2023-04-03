import ast

node = ast.parse('x + y +  17 * (5+9+9+(11)) / (100 - 2 -2)', mode='eval')
exp = node.body

print(ast.dump(exp, indent=4))
def eval(exp):
    if type(exp) != ast.BinOp:
        return exp
    exp.left = eval(exp.left)
    exp.right= eval(exp.right)
    if type(exp.left) == ast.Constant and type(exp.right) == ast.Constant:
        l, r, val = exp.left.value , exp.right.value, 0
        if type(exp.op) == ast.Mult:
            val = l * r
        elif type(exp.op) == ast.Add:
            val = l + r
        elif type(exp.op) == ast.Div:
            val = l + r
        elif type(exp.op) == ast.Sub:
            val = l + r
        return ast.Constant(val)
    return exp
r = eval(node.body)
print(ast.dump(r, indent=4))

def asm(exp):
    ans = ''
    