<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Игра</h1>
                <table border="5" align="center">
                    <tr>
                        <th>Име на автора</th>
                        <th>Публикувани игре</th>
                        <th>Националност на автора</th>
                        <th>Година на раждане</th>
                        <th>Година на смъртта</th> 
                    </tr>         
                    <xsl:for-each select="game_library/game">
                        <tr>
                            <td>
                                <xsl:call-template name="game-authors-author-author_name"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-authors-author-published_games"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-authors-author-nationality"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-authors-author-birth_day-date"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-authors-author-death_day-date"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="game-authors-author-author_name">
        <xsl:value-of select="authors/author/author_name/."/>
    </xsl:template>

    <xsl:template name="game-authors-author-published_games">
        <xsl:value-of select="authors/author/published_games/."/>
    </xsl:template>

    <xsl:template name="game-authors-author-nationality">
        <xsl:value-of select="authors/author/nationality/."/>
    </xsl:template>

    <xsl:template name="game-authors-author-birth_day-date">
        <xsl:value-of select="authors/author/birth_day/date/@year/."/>
    </xsl:template>

    <xsl:template name="game-authors-author-death_day-date">
        <xsl:value-of select="game-authors-author-death_day-date/@day/@month/@year/."/>
    </xsl:template>

</xsl:stylesheet>