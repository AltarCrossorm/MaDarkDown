"""
Parser objects for MaDarkDown handleing
"""

class MDD_Object:
        def __init__(self,value:str) -> None:
                self.value = value
        
        def __str__(self) -> str:
                return self.value
        
        def __repr__(self) -> str:
                return self.value
        
class MDD_Text(MDD_Object):
        def __init__(self, value: str) -> None:
                super().__init__(value)
                
        def __str__(self) -> str:
                return f"<p>{self.value}</p>"
        
class MDD_Header(MDD_Text):
        def __init__(self, value: str, header_size:int) -> None:
                super().__init__(value)
                self.size = header_size
                
        def __str__(self) -> str:
                return f"<h{self.size}>{self.value}</h{self.size}>"
        

def MDD_unbatch(final:list[MDD_Object]):
        ret:str = ""
        
        for obj in final:
                ret += f"{obj}\n\n"
                
        return ret