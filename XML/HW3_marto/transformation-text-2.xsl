<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/">
        <xsl:for-each select="board-game-store/game">

            Име:
            <xsl:value-of select="title"/>

            <xsl:if test="other-title">
                Друго име на играта:
                <xsl:value-of select="other-title"/>
            </xsl:if>
            <xsl:if test="not(other-title)">
                Друго име на играта: няма
            </xsl:if>

            ISIN на създателя на играта:
            <xsl:value-of select="publisher/@isin"/>
            Име на създателя на играта:
            <xsl:value-of select="publisher/name"/>

        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>