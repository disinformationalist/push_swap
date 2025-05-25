import subprocess
from itertools import permutations

PUSH_SWAP = "./push_swap"
TARGET_LENGTH = 9

def count_operations(output: str):
    return len(output.strip().splitlines())

def main():
    perms = permutations([1, 2, 3, 4, 5])
    worst_cases = []

    for p in perms:
        args = list(map(str, p))
        try:
            result = subprocess.run(
                [PUSH_SWAP] + args,
                capture_output=True,
                text=True,
                timeout=1
            )
            op_count = count_operations(result.stdout)
            if op_count == TARGET_LENGTH:
                worst_cases.append((p, op_count))
        except subprocess.TimeoutExpired:
            print(f"Timeout on input: {p}")
        except Exception as e:
            print(f"Error on input {p}: {e}")

    print(f"\nPermutations needing exactly {TARGET_LENGTH} operations:\n")
    for p, count in worst_cases:
        print(f"{p} -> {count} ops")

if __name__ == "__main__":
    main()
