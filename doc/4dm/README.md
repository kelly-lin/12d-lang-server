# 12d Documentation Patching

This project automatically generates the 12dpl library documentation to display
in language services (e.g. showing documentation when hovering over a 12dpl
library function) by mapping the functions defined in a protypes file with
the 12d programming manual with the script `/doc/4dm/gen_doc.py`.

The automatic generation allows us to gather the large amount of documentation
very quickly, but also comes at a price with many errors such as:

- Incorrect spacing.
- Inclusion of PDF header/footer text included in function call descriptions.
- Inclusion of junk symbol chacaracters in the text.
- Other errors.

To address these issues, a documentation patching system has been implemented to
correct the mistakes.

## How to create a patch

1. Locate the library function you would like to patch in
   `/doc/4dm/generated.json` and make your changes directly in the file.
   For example, if we wanted to change the description of the manual item shown
   below, we would edit and save the change in the `/doc/4dm/generated.json`
   file.

   ```json
   {
     "items": [
       {
         "names": ["void Exit(Integer exit_code)"],
         "description": "some wrong description",
         "id": "417"
       }
     ]
   }
   ```

   ```json
   {
     "items": [
       {
         "names": ["void Exit(Integer exit_code)"],
         "description": "Immediately exit the program and write the message macro exited with code exit_code to the information/error message area of the macro console panel.",
         "id": "417"
       }
     ]
   }
   ```

2. Open up a terminal and run the patcher script `make genpatch`. This will
   create a new patch in `/doc/4dm/patch.json` if it does not exist, otherwise
   it will be modified if it does.
3. Run the command to update the library `make genlib`. This will regenerate the
   go code that the language server uses to serve documentation to the client.
4. Commit changes and open a pull request.
