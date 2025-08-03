

class mdd_Parser_Exception(Exception):
        def __init__(self, args: object) -> None:
                self.message:str = args # type: ignore
        
        def __str__(self) -> str:
                return self.message
        
                