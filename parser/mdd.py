"""
Comment qu'on fait un parser :
1 - On lit la ligne
2 - Si on voit un élément on le prends en compte,
2.1 - Si un élément existait déjà, on l'ajoute, sinon on en crée un nouveau (voire erreur)
3 - On continue de lire la ligne
4 - si ne fin d'élément est détectée, on l'ajoute à la liste, sinon par défaut c'est du texte
5 - on recommence le processus jusqu'à la fin de la ligne
"""

from .parser_exceptions import mdd_Parser_Exception
from .mdd_objects import *
from md2pdf.core import md2pdf # type: ignore


def mdd_parse(*args:str) -> None:
        
        mdd_file:str = ""
        css_file:str = ""
        
        
        if(len(args) < 2):
                raise mdd_Parser_Exception("No file was provided")
        
        mdd_file = args[1]
        
        if not args[1].endswith('.mdd'):
                raise mdd_Parser_Exception("File must end with a .mdd extension")
                
        if len(args) == 3:
                css_file = args[2]
        
        if css_file and not css_file.endswith('.css'):
                raise mdd_Parser_Exception("Style file must end with .css extension")
        
        mdd_list:list[MDD_Object] = []
        
        with open(mdd_file) as MDDf:
                lines = MDDf.read().split('\n') # Make the variable as a list of lines
                
                for line in lines:
                        match line: # Mode first-character (headers, tables, notes, variables, ...)
                                case header if line.startswith('#'):
                                        size = list(line)
                                        i=0
                                        while size[i] == '#':
                                                i+=1
                                        mdd_list.append(MDD_Header(header[i+1:], i))
                                case var if line.startswith('!var'):
                                        print(var)
                                        mdd_list.append(MDD_Text(line))
                                        
                                case _: # Now in-line types (bold, italic, code, spoilers, ...)
                                        for char in line:
                                                pass                                       
                                        mdd_list.append(MDD_Text(line))
                                

        md2pdf(
                pdf_file_path="./mdd_pdf.pdf",
                md_content=MDD_unbatch(mdd_list)
                )
                