<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/">
        <xsl:for-each select="board-game-store/game">

            Име:
            <xsl:value-of select="title"/>
            Тип на играта:
            <xsl:value-of select="skill"/>
            Трудност на играта:
            <xsl:value-of select="difficulty/@level"/>

        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>