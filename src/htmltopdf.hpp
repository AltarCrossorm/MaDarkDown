#pragma once

#include <wkhtmltox/pdf.h>
#include <string>

/**
 * @brief Une classe minimaliste pour convertir du HTML en PDF.
 * Note : wkhtmltopdf nécessite que l'init/deinit ne soit fait qu'une seule fois 
 * par cycle de vie de l'application.
 */
class PDFGenerator {
public:
    enum class Status {
        Success,
        InitFailed,
        ConversionFailed
    };

private:
        Status generatorStatus;


public:

    PDFGenerator() {
        // Initialisation de la bibliothèque (obligatoire une seule fois)
        // On utilise l'argument 0 car on ne gère pas de rendu graphique (headless)
        if(!wkhtmltopdf_init(0))
                generatorStatus = Status::InitFailed;
    }

    ~PDFGenerator() {
        wkhtmltopdf_deinit();
    }

    /**
     * @brief Convertit une string HTML brute en fichier PDF.
     * @param html Content HTML complet.
     * @param output_path Chemin du fichier de sortie (ex: "output.pdf").
     */
    Status createFromRawHtml(const std::string& html, const std::string& output_path) {
        wkhtmltopdf_global_settings* gs = wkhtmltopdf_create_global_settings();
        
        // Configuration de la sortie
        wkhtmltopdf_set_global_setting(gs, "out", output_path.c_str());
        wkhtmltopdf_set_global_setting(gs, "load.cookieJar", "cookies.txt");

        wkhtmltopdf_object_settings* os = wkhtmltopdf_create_object_settings();
        
        // On crée le convertisseur
        wkhtmltopdf_converter* c = wkhtmltopdf_create_converter(gs);

        // Ajout du contenu HTML
        // wkhtmltopdf_add_object prend les réglages et les données HTML
        wkhtmltopdf_add_object(c, os, html.c_str());

        // Exécution de la conversion
        bool success = wkhtmltopdf_convert(c);

        // Nettoyage
        wkhtmltopdf_destroy_converter(c);
        // Les settings sont consommés par le converter, mais par sécurité :
        // wkhtmltopdf_destroy_global_settings(gs); 

        return success ? Status::Success : Status::ConversionFailed;
    }

    auto getStatus(void) -> Status
    {
        return generatorStatus;
    }

};
