<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/">
        <xsl:for-each select="game_library/game">

            Име:
            <xsl:value-of select="game_name"/>

            Издател:
            <xsl:value-of select="publisher"/>

            Автор на играта:
            <xsl:value-of select="authors/author/author_name"/>

            Националност на автора:
            <xsl:value-of select="authors/author/nationality"/>

            Дата на раждане:
            <xsl:value-of select="authors/author/birth_day/date/@year"/>

        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>