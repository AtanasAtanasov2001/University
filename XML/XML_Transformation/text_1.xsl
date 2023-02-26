<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/">
        <xsl:for-each select="game_library/game">

            Име: <xsl:value-of select="game_name/."/>
            Цена: <xsl:value-of select="price/."/>
            Рейтинг: <xsl:value-of select="rating/."/>
            Жанр: <xsl:value-of select="genres/genre/@name"/>
            Език: <xsl:value-of select="language/@name"/>

        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>