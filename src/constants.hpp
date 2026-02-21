#pragma once

enum class ExitValue
{
        ERR_FILE_NOT_FOUND,
};

enum class LanguagesList
{
    af_ZA, // Afrikaans (Afrique du Sud)

    am_ET, // Amharique (Éthiopie)

    ar_AE, // Arabe (Émirats arabes unis)
    ar_BH, // Arabe (Bahreïn)
    ar_DZ, // Arabe (Algérie)
    ar_EG, // Arabe (Égypte)
    ar_IQ, // Arabe (Iraq)
    ar_JO, // Arabe (Jordanie)
    ar_KW, // Arabe (Koweït)
    ar_LB, // Arabe (Liban)
    ar_LY, // Arabe (Libye)
    ar_MA, // Arabe (Maroc)
    ar_OM, // Arabe (Oman)
    ar_QA, // Arabe (Qatar)
    ar_SA, // Arabe (Arabie saoudite)
    ar_SY, // Arabe (Syrie)
    ar_TN, // Arabe (Tunisie)
    ar_YE, // Arabe (Yémen)

    as_IN, // Assamais (Inde)

    az_AZ, // Azéri (Azerbaïdjan)

    be_BY, // Biélorusse (Bélarus)

    bg_BG, // Bulgare (Bulgarie)

    bn_BD, // Bengali (Bangladesh)
    bn_IN, // Bengali (Inde)

    bs_BA, // Bosniaque (Bosnie-Herzégovine)

    ca_ES, // Catalan (Espagne)

    cs_CZ, // Tchèque (République tchèque)

    cy_GB, // Gallois (Royaume-Uni)

    da_DK, // Danois (Danemark)

    de_AT, // Allemand (Autriche)
    de_CH, // Allemand (Suisse)
    de_DE, // Allemand (Allemagne)
    de_LI, // Allemand (Liechtenstein)
    de_LU, // Allemand (Luxembourg)

    el_GR, // Grec (Grèce)

    en_AU, // Anglais (Australie)
    en_BZ, // Anglais (Belize)
    en_CA, // Anglais (Canada)
    en_GB, // Anglais (Royaume-Uni)
    en_IE, // Anglais (Irlande)
    en_IN, // Anglais (Inde)
    en_JM, // Anglais (Jamaïque)
    en_NZ, // Anglais (Nouvelle-Zélande)
    en_PH, // Anglais (Philippines)
    en_TT, // Anglais (Trinité-et-Tobago)
    en_US, // Anglais (États-Unis)
    en_ZA, // Anglais (Afrique du Sud)
    en_ZW, // Anglais (Zimbabwe)

    es_AR, // Espagnol (Argentine)
    es_BO, // Espagnol (Bolivie)
    es_CL, // Espagnol (Chili)
    es_CO, // Espagnol (Colombie)
    es_CR, // Espagnol (Costa Rica)
    es_DO, // Espagnol (République dominicaine)
    es_EC, // Espagnol (Équateur)
    es_ES, // Espagnol (Espagne)
    es_GT, // Espagnol (Guatemala)
    es_HN, // Espagnol (Honduras)
    es_MX, // Espagnol (Mexique)
    es_NI, // Espagnol (Nicaragua)
    es_PA, // Espagnol (Panama)
    es_PE, // Espagnol (Pérou)
    es_PR, // Espagnol (Porto Rico)
    es_PY, // Espagnol (Paraguay)
    es_SV, // Espagnol (El Salvador)
    es_US, // Espagnol (États-Unis)
    es_UY, // Espagnol (Uruguay)
    es_VE, // Espagnol (Venezuela)

    et_EE, // Estonien (Estonie)

    eu_ES, // Basque (Espagne)

    fa_IR, // Persan (Iran)

    fi_FI, // Finnois (Finlande)

    fo_FO, // Féroïen (Îles Féroé)

    fr_BE, // Français (Belgique)
    fr_CA, // Français (Canada)
    fr_CH, // Français (Suisse)
    fr_FR, // Français (France)
    fr_LU, // Français (Luxembourg)
    fr_MC, // Français (Monaco)
    fr_SN, // Français (Sénégal)
    fr_CI, // Français (Côte d'Ivoire)
    fr_CM, // Français (Cameroun)
    fr_MA, // Français (Maroc)

    gl_ES, // Galicien (Espagne)

    gu_IN, // Goudjarati (Inde)

    he_IL, // Hébreu (Israël)

    hi_IN, // Hindi (Inde)

    hr_HR, // Croate (Croatie)

    hu_HU, // Hongrois (Hongrie)

    hy_AM, // Arménien (Arménie)

    id_ID, // Indonésien (Indonésie)

    is_IS, // Islandais (Islande)

    it_CH, // Italien (Suisse)
    it_IT, // Italien (Italie)

    ja_JP, // Japonais (Japon)

    ka_GE, // Géorgien (Géorgie)

    kk_KZ, // Kazakh (Kazakhstan)

    kn_IN, // Kannada (Inde)

    ko_KR, // Coréen (Corée du Sud)

    kok_IN, // Konkani (Inde)

    ky_KG, // Kirghize (Kirghizistan)

    lt_LT, // Lituanien (Lituanie)

    lv_LV, // Letton (Lettonie)

    mk_MK, // Macédonien (Macédoine)

    ml_IN, // Malayalam (Inde)

    mn_MN, // Mongol (Mongolie)

    mr_IN, // Marathi (Inde)

    ms_BN, // Malais (Brunéi Darussalam)
    ms_MY, // Malais (Malaisie)

    mt_MT, // Maltais (Malte)

    nb_NO, // Norvégien Bokmål (Norvège)

    ne_NP, // Népalais (Népal)

    nl_BE, // Néerlandais (Belgique)
    nl_NL, // Néerlandais (Pays-Bas)

    nn_NO, // Norvégien Nynorsk (Norvège)

    or_IN, // Oriya (Inde)

    pa_IN, // Pendjabi (Inde)

    pl_PL, // Polonais (Pologne)

    ps_AF, // Pashto (Afghanistan)

    pt_BR, // Portugais (Brésil)
    pt_PT, // Portugais (Portugal)

    ro_RO, // Roumain (Roumanie)

    ru_RU, // Russe (Russie)

    sa_IN, // Sanskrit (Inde)

    sk_SK, // Slovaque (Slovaquie)

    sl_SI, // Slovène (Slovénie)

    sq_AL, // Albanais (Albanie)

    sr_RS, // Serbe (Serbie)

    sv_FI, // Suédois (Finlande)
    sv_SE, // Suédois (Suède)

    sw_KE, // Swahili (Kenya)

    ta_IN, // Tamoul (Inde)

    te_IN, // Télougou (Inde)

    th_TH, // Thaï (Thaïlande)

    tr_TR, // Turc (Turquie)

    uk_UA, // Ukrainien (Ukraine)

    ur_PK, // Ourdou (Pakistan)

    uz_UZ, // Ouzbek (Ouzbékistan)
    
    vi_VN, // Vietnamien (Viet Nam)

    zh_CN, // Chinois (Chine)
    zh_HK, // Chinois (Hong Kong)
    zh_MO, // Chinois (Macao)
    zh_SG, // Chinois (Singapour)
    zh_TW  // Chinois (Taïwan)
};