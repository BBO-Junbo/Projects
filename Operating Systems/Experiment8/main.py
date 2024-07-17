class FileSystem:
    def __init__(self):
        self.root = {'content': {}, 'type': 'directory'}

    def create_file(self, path, content):
        current = self.root
        folders = path.split('/')
        for folder in folders[:-1]:
            if folder not in current['content']:
                current['content'][folder] = {'content': {}, 'type': 'directory'}
            current = current['content'][folder]
        current['content'][folders[-1]] = {'content': content, 'type': 'file'}

    def create_folder(self, path):
        current = self.root
        folders = path.split('/')
        for folder in folders:
            if folder not in current['content']:
                current['content'][folder] = {'content': {}, 'type': 'directory'}
            current = current['content'][folder]

    def get_content(self, path):
        current = self.root
        folders = path.split('/')
        for folder in folders[:-1]:
            current = current['content'][folder]
        file = current['content'].get(folders[-1], None)
        if file and file['type'] == 'file':
            return file['content']
        else:
            return None

    def display_file_system(self, node=None, path='', indent=0):
        if node is None:
            node = self.root['content']
        for name, details in node.items():
            new_path = f"{path}/{name}" if path else name
            print('  ' * indent + f"- {new_path}")
            if details['type'] == 'directory':
                self.display_file_system(details['content'], new_path, indent + 1)
            else:
                print('  ' * (indent + 1) + f"Content: {details['content']}")

    def modify_content(self, path, new_content):
        current = self.root
        folders = path.split('/')
        for folder in folders[:-1]:
            current = current['content'][folder]
        file = current['content'].get(folders[-1], None)
        if file and file['type'] == 'file':
            file['content'] = new_content
            print(f"Content of {path} modified successfully.")
        else:
            print(f"{path} is not a valid file.")

    def delete_file(self, path):
        current = self.root
        folders = path.split('/')
        for folder in folders[:-1]:
            current = current['content'][folder]
        file = current['content'].get(folders[-1], None)
        if file and file['type'] == 'file':
            del current['content'][folders[-1]]
            print(f"{path} deleted successfully.")
        else:
            print(f"{path} is not a valid file.")


fs = FileSystem()

fs.create_folder("root/folder1")
fs.create_file("root/folder1/file1.txt", "Hello, this is file1 content.")
fs.create_folder("root/folder2")
fs.create_file("root/folder2/file2.txt", "Hello, this is file2 content.")

fs.display_file_system()
fs.modify_content("root/folder1/file1.txt", "Modified content for file1.")
fs.display_file_system()
fs.delete_file("root/folder2/file2.txt")
fs.display_file_system()
