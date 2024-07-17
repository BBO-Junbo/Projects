class Lexer:
    def __init__(self):
        self.string = ""
        self.pointer = 0
        self.keywords = {
            "int": (5, "-"),
            "else": (15, "-"),
            "if": (17, "-"),
            "while": (20, "-")
        }

        self.constants = {
            "整数": (100, "整数")
        }

        self.operators = {
            "+": (41, "-"),
            "-": (42, "-"),
            "*": (43, "-"),
            "/": (44, "-"),
            "%": (45, "-"),
            "=": (46, "-"),
            ">": (47, "-"),
            ">=": (48, "-"),
            "<": (49, "-"),
            "<=": (50, "-"),
            "==": (51, "-"),
            "!=": (52, "-"),
            "&&": (53, "-"),
            "||": (54, "-"),
            "!": (55, "-"),
            "++": (56, "-"),
            "--": (57, "-")
        }

        self.delimiters = {
            "(": (81, "-"),
            ")": (82, "-"),
            ";": (84, "-"),
            "{": (86, "-"),
            "}": (87, "-"),
            "[": (88, "-"),
            "]": (89, "-")
        }
        
    def count_tokens(self):
        tokens = []
        current_token = ""
        i = 0
        while i < len(self.string):
            if self.string[i].isdigit():  # Check if the character is a digit
                current_token += self.string[i]
                i += 1
                while i < len(self.string) and self.string[i].isdigit():
                    current_token += self.string[i]
                    i += 1
                tokens.append(self.constants["整数"])  # Append the Integer constant
                current_token = ""
            elif self.string[i].isalnum() or self.string[i] == '_':
                current_token += self.string[i]
                i += 1
                while i < len(self.string) and (self.string[i].isalnum() or self.string[i] == '_'):
                    current_token += self.string[i]
                    i += 1
                if current_token in self.keywords:
                    tokens.append(self.keywords[current_token])
                else:
                    tokens.append(self.is_identifier(current_token))
                current_token = ""
            elif self.string[i] in self.operators or self.string[i:i+2] in self.operators:
                if self.string[i:i+2] in self.operators:
                    tokens.append(self.operators[self.string[i:i+2]])
                    i += 2
                else:
                    tokens.append(self.operators[self.string[i]])
                    i += 1
            elif self.string[i] in self.delimiters:
                tokens.append(self.delimiters[self.string[i]])
                i += 1
            elif self.string[i].isspace():
                i += 1
            else:
                raise ValueError("Illegal character: {}".format(self.string[i]))
        return len(tokens)
    
    def is_identifier(self, token):
        return 111, token

    def get_next_token(self):
        char = self.string[self.pointer]
        token=""
        if char.isdigit():  # Check if the character is a digit
            token = char
            self.pointer += 1
            while self.pointer < len(self.string) and self.string[self.pointer].isdigit():
                token += self.string[self.pointer]
                self.pointer += 1
            return self.constants["整数"]  # Return the Integer constant
        elif char.isalnum() or char == '_':
            token = char
            self.pointer += 1
            while self.pointer < len(self.string) and (self.string[self.pointer].isalnum() or self.string[self.pointer] == '_'):
                token += self.string[self.pointer]
                self.pointer += 1
            if token in self.keywords:
                return self.keywords[token]
            else:
                return self.is_identifier(token)
        elif char in self.operators or (self.string[self.pointer:self.pointer + 2]) in self.operators:
            if (self.string[self.pointer:self.pointer + 2]) in self.operators:
                self.pointer += 2
                return self.operators[self.string[self.pointer-2:self.pointer]]
            else:
                self.pointer += 1
                return self.operators[char]
        elif char in self.delimiters:
            self.pointer += 1
            return self.delimiters[char]
        elif char.isspace():
            self.pointer += 1
            return self.get_next_token()

    def analyze(self):
        if self.pointer >= len(self.string):
            return None
        return self.get_next_token()

    def analyze_file(self, file_path):
        try:
            with open(file_path, 'r') as file:
                file_content = file.read()  # Read file contents once
                self.string = file_content  # Assign the content to self.string
                self.token_num = self.count_tokens()
        except FileNotFoundError:
            print("File not found:", file_path)
